'''
2. Creare un client con GUI (tkinter):
• Campo per inserire il numero da provare.
• Bottone “Prova”.
• Area testo per mostrare messaggi dal server.
3. Il client invia i tentativi al server e mostra la risposta in GUI.
'''


import socket
import tkinter as tk
from tkinter import messagebox

PORT = 12345
HOST = '127.0.0.1'


client_socket = None #variabile globale

def connessione():
    global client_socket # global server per specificare che client scoket non è una variabile locale ma è quella che si trova all'esterno
    # global deve essere utilizzato quando si sta assegnando un valore alla variabile globale 
    try:
        
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((HOST, PORT))
        
    except ConnectionRefusedError:
        messagebox.showerror("Errore", "Server non attivo")
        root.destroy()

def pulsante():
    
    msg = entry.get()
    
    # Controlla se l'utente ha lasciato il campo vuoto   
    if not msg.strip():
        messagebox.showwarning("ATTENZIONE", "Inserire un numero")
        return
    
    try:
         # Invia il messaggio trasformandolo in bytes
        client_socket.sendall(msg.encode())
                
         # Riceve la risposta del server (max 1024 byte)
        data = client_socket.recv(1024).decode()
                
        # Mostra la risposta in una finestra popup            
        messagebox.showinfo("Risultato: ", data)
                
        if data == "Hai vinto":
            client_socket.close()
            root.destroy()  # destroy server per terminare il loop e chiudere la finestra 
            
    except ConnectionRefusedError:
        # Caso in cui il server NON è avviato        
        messagebox.showerror("Errore", "Il server non è attivo.")
            
# ===============================
#       COSTRUZIONE GUI
# ===============================

root = tk.Tk() # Crea la finestra principale
root.title("Clien Python")

connessione()

# Frame per contenere gli elementi grafici (solo estetica)
frame = tk.Frame(root, padx=100, pady=160)
frame.pack()

# Etichetta
label = tk.Label(frame, text="Indovina il numero:")
label.pack()

# Casella di input
entry = tk.Entry(frame, width=60)
entry.pack(pady=20)

# Pulsante che richiama pulsante()
btn = tk.Button(frame, text="Invia al server", command=pulsante)
btn.pack()

# Avvia il loop grafico della finestra
root.mainloop()

