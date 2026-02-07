import socket

def start_server():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('127.0.0.1', 12345))  # Indirizzo e porta
    server_socket.listen(5)
    print("Server in ascolto sulla porta 12345...")
    conn, addr = server_socket.accept()
    print(f"Connessione stabilita con {addr}")
    dati = []  # qui memorizziamo tutto
    fine = False
    

    while True:
        # Se il client chiude la connessione
        messaggio = conn.recv(1024).decode()
        if not messaggio:
            break
        
        # Rimozione spazi e separazione in righe
        righe = messaggio.strip().split("\n")
        
        # Analisi di ogni riga ricevuta
        for riga in righe:

            if riga == "FINE":
                fine = True
                break
            
            # Separazione dei dati ricevuti
            data, tempAM, tempPM = riga.split(";")
            tempAM = float(tempAM)
            tempPM = float(tempPM)

            # questo array mi servirà per fare i calcoli dopo
            dati.append((data, tempAM, tempPM))

            print(f"Data: {data}")
            print(f"Temperatura AM: {tempAM}")
            print(f"Temperatura PM: {tempPM}")

        if fine:
            break
            
    every_temperature = []
    
    for d in dati:
        every_temperature.append(d[1]) #utilizzo append perchè non va a sostituire le variabili all'interno dell'array
        every_temperature.append(d[2])
        
        
    media = sum(every_temperature)/len(every_temperature)
    temp_min = min(every_temperature)
    temp_max = max(every_temperature)
    
    risultato = (
    f"Temperatura media complessiva: {media:.2f}\n"
    f"Temperatura massima registrata: {temp_max:.2f}\n"
    f"Temperatura minima registrata: {temp_min:.2f}\n"
    )
    
    conn.sendall(risultato.encode())
    
    conn.close()    
    server_socket.close()

if __name__ == "__main__":
    start_server()