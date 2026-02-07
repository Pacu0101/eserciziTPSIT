import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # variabile che contiene la socket
    client_socket.connect(('localhost', 12345)) # localhost = connessione con il server, 12345 = numero della porta in ascolto 
        
    print("Ricerca di un taxi disponibile...")
    data = client_socket.recv(1024).decode() 
        
    if data == "Nessun taxi disponibile":
        print(f"{data}")
        client_socket.close()        
        return
   
    print(f"Il taxi numero {data} è disponibile")

    partenza = input("Inserisca la citta di partenza: ").strip()
    while partenza == "": # controllo per vedere se la stringa è vuota. Strip è un metodo che invia la stringa senza gli spazi
        partenza = input("Inserisci un città di partenza valida: ").strip()
        
    arrivo = input("Inserisca la città di arrivo: ").strip()
    while arrivo == "":
        arrivo = input("Inserisci un città di partenza valida: ").strip()
        
    client_socket.sendall(partenza.encode()) 
    client_socket.sendall(arrivo.encode()) 
        
    print("Grazie per aver prenotato e buon viaggio")



if __name__ == "__main__":
    start_client()
