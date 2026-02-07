import socket
import threading

MAX_TAXI = 3

# Variabile globale: contatore dei taxi attualmente assegnati
n = 0
# Lock (lucchetto): garantisce accesso esclusivo alla variabile 'n' per evitare race condition
lock = threading.Lock()

def servizio(conn, addr):

    global n  # Dichiara che useremo la variabile globale 'n'

    try:
        with lock:  # Acquisisce il lock (solo un thread alla volta può entrare)
            if n >= MAX_TAXI:
                conn.send("Nessun taxi disponibile".encode())  
                return
            
        conn.send("OK".encode())     

        data1 = conn.recv(1024).decode()
        if not data1:  # Se non riceve dati (connessione chiusa)
            return

        data2 = conn.recv(1024).decode()
        if not data2:
            return

        print(f"Partenza: {data1}")
        print(f"Arrivo: {data2}")

        with lock:  # Acquisisce il lock per proteggere 'n'    
            n += 1  # Solo un thread alla volta può eseguire questa riga
            taxi_id = n
                
        conn.send(str(taxi_id).encode())

    except (ConnectionResetError, OSError):
        # Gestisce il caso in cui il client si disconnette improvvisamente
        print(f"Client {addr} disconnesso improvvisamente")

    finally:
        conn.close()
    print(f"Connessione terminata con {addr}")  
        
        

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', 12345))  # Indirizzo e porta
    server_socket.listen(5)
    print("Server in ascolto sulla porta 12345...")
    
    while(1):
        conn, addr = server_socket.accept()
        print(f"Connessione stabilita con {addr}")
        
        client_thread = threading.Thread(
            target=servizio,    # Funzione da eseguire nel thread
            
            args=(conn,addr)  # Argomenti da passare alla funzione
        )

        client_thread.start()
    

if __name__ == "__main__":
    start_server()