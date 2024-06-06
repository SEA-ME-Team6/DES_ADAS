import socket

def main():
    host = '192.168.86.39'  # IP address of local
    port = 3332            # Port num which has to be same as LKAS port num

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((host, port))
    server_socket.listen()

    print('Server started. Waiting for connection...')

    client_soc = None

    try:
        client_soc, addr = server_socket.accept()
        print('Connected client addr:', addr)

        while True:
            user_input = input("Enter an integer to send to the client (or 'exit' to quit): ")
            
            if user_input.lower() == 'exit':
                break
            
            try:
                integer_value = int(user_input)
                data = integer_value.to_bytes(4, byteorder='big', signed=True)
                client_soc.sendall(data)
                print(f"Sent {integer_value} to the client.")
            except ValueError:
                print("Invalid input. Please enter a valid integer.")
    
    except KeyboardInterrupt:
        print('KeyboardInterrupt received. Server closing...')

    finally:
        if client_soc:
            client_soc.close()
        server_socket.close()

    print('Server is terminated')

if __name__ == '__main__':
    main()
