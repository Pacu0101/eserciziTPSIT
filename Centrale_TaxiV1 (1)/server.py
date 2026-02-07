import socket
import threading

MAX_TAXI = 3

n = 1

def servizio(conn, addr):

    global n
        
    while(1):
                
        if MAX_TAXI < n:
            msg = "Nessun taxi disponibile"
            conn.send(msg.encode())
            return
        
        nTaxi = str(n)
        conn.send(nTaxi.encode())

        data1 = conn.recv(1024).decode()
        data2 = conn.recv(1024).decode()    
        print(f"Città di partenza: {data1}")
        print(f"Città di arrivo: {data2}")
        n = n + 1

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
            target=servizio,
            
            args=(conn,addr)
        )

        client_thread.start()
    

if __name__ == "__main__":
    start_server()