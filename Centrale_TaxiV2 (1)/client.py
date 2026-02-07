import socket
import tkinter as tk
from tkinter import messagebox



def prenotazione():
    
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM) # variabile che contiene la socket
    client_socket.connect(('localhost', 12345)) # localhost = connessione con il server, 12345 = numero della porta in ascolto 
        
    # Recupera il testo inserito dall'utente nel campo "partenza" e rimuove spazi vuoti
    partenza = entry_partenza.get().strip()
    
    # Validazione: controlla che l'utente abbia inserito una città di partenza
    if partenza == "":
        messagebox.showwarning("Errore", "Inserisci una città di partenza valida")
        client_socket.close()
        return
    
    arrivo = entry_arrivo.get().strip()
    if arrivo == "":
        messagebox.showwarning("Errore", "Inserisci una città di arrivo valida")
        client_socket.close()
        return

    # Riceve la prima risposta dal server (max 1024 bytes) e la decodifica da bytes a stringa
    data = client_socket.recv(1024).decode() 
      
    # Se il server comunica che non ci sono taxi disponibili  
    if data == "Nessun taxi disponibile":
        messagebox.showinfo("Info",data)  # Mostra messaggio informativ
        client_socket.close()  # Chiude la socket        
        return  # Esce dalla funzione
    
    messagebox.showinfo("Info", "Taxi disponibile! Invio dati...")
   
        
    client_socket.sendall(partenza.encode()) 
    client_socket.sendall(arrivo.encode()) 
    
    taxi = client_socket.recv(1024).decode()
    messagebox.showinfo("Info",f"Il taxi numero {taxi} è disponibile")
        
    messagebox.showinfo("Info","Grazie per aver prenotato e buon viaggio")
    
    client_socket.close()
    root.destroy()

# ===============================
#       COSTRUZIONE GUI
# ===============================

# Crea la finestra principale dell'applicazione
root = tk.Tk()
print("GUI partita")  # Messaggio di debug sulla console

# Imposta il titolo della finestra
root.title("Client")

# Crea un frame (contenitore) con padding di 100px orizzontale e 160px verticale
frame = tk.Frame(root, padx=100, pady=160)
frame.pack()  # Posiziona il frame nella finestra

# Crea un'etichetta (label) con il testo per l'utente
label = tk.Label(frame, text="Inserisci la città di partenza:")
label.pack()  # Aggiunge la label al frame

# Crea un campo di input (entry) largo 30 caratteri
entry_partenza = tk.Entry(frame, width=30)
entry_partenza.pack(pady=15)  # Aggiunge spazio verticale di 15px sopra e sotto

# Crea un'altra etichetta per la città di arrivo
label = tk.Label(frame, text="Inserisci la città di arrivo:")
label.pack()

# Crea un secondo campo di input per la città di arrivo
entry_arrivo = tk.Entry(frame, width=30)
entry_arrivo.pack(pady=15)

# Crea un bottone che chiama la funzione prenotazione() quando viene cliccato
btn = tk.Button(frame, text="Prenota", command=prenotazione)
btn.pack()

# Avvia il loop principale della GUI (rimane in attesa di eventi come click)
root.mainloop()