import socket

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 12345))

    cont_days = 0
    cont_rilevazioni = 0
    
    while True:
        data = input("Inserire la data (gg/mm/aaaa): ")
        temperaturaAM = input("Inserisci la temperatura alle ore 12:00: ")
        temperaturaPM = input("Inserisci la temperatura alle ore 24:00: ")

        messaggio = f"{data};{temperaturaAM};{temperaturaPM}\n"
        client_socket.sendall(messaggio.encode())

        cont_days += 1
        cont_rilevazioni += 2
        
        risposta = input("Continuare a inserire altre date? y/n ")
        if risposta.lower() in ("n", "no"):
            client_socket.sendall("FINE\n".encode())
            break
        
    risultato = client_socket.recv(1024).decode()
    print("Risultato delle analisi:")
    print(f"Numero di giorni analizzati: {cont_days}")
    print(f"Numero di rilevazioni fate: {cont_rilevazioni}")
    print(risultato)
    
    client_socket.close()

if __name__ == "__main__":
    start_client()