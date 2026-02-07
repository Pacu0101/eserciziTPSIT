import random

'''
1. Creare un server TCP che:
• Genera un numero casuale tra 1 e 100.
• Attende i tentativi dei client.
• Risponde con “Troppo alto”, “Troppo basso” o “Hai vinto”.
'''

import socket
HOST = '127.0.0.1'
PORT = 12345

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))  # Indirizzo e porta
    server_socket.listen(5)
    print("Server in ascolto sulla porta 12345...")
    
    n = random.randint(1,100)
    print(f"Numero random: {n}")
    
    conn, addr = server_socket.accept() # il accept deve essere messo fuori dal while perchè si deve connettere solo una volta per il client
    print(f"Connessione stabilita con {addr}")
    
    while(1):

        data = conn.recv(1024).decode()
        
        if not data:              
            print("Client disconnesso")
            break
    
        print(f"Messaggio ricevuto: {data}")

        try: 
            data = int(data) 
        except ValueError:
            conn.sendall("Inserisci un numero valido")
            continue
        # se data non viene cambiato in int da errore perchè si sta facendo un confronto tra int e str
        
        if data > n:
            response = "Troppo altro"
            conn.send(response.encode())
        elif data == n:
            response = "Hai vinto"
            conn.send(response.encode()) 
            break  
        else:
            response = "Troppo basso"
            conn.send(response.encode())     
        
    conn.close()
    
    server_socket.close()

if __name__ == "__main__":
    start_server()