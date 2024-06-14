import socket
import time

def main():
    host = '192.168.86.39'  # IP address of local
    port = 3333             # Port num which has to be same as LKAS port num

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((host, port))
    server_socket.listen()

    print('Server started. Waiting for connection...')

    client_soc = None

    try:
        client_soc, addr = server_socket.accept()
        print('Connected client addr:', addr)

        integer_value = 1
        data = integer_value.to_bytes(4, byteorder='big', signed=True)

        while True:
            client_soc.sendall(data)
            print(f"Sent {integer_value} to the client.")
            time.sleep(1)  # Adjust the sleep time as needed
    
    except KeyboardInterrupt:
        print('KeyboardInterrupt received. Server closing...')

    finally:
        if client_soc:
            client_soc.close()
        server_socket.close()

    print('Server is terminated')

if __name__ == '__main__':
    main()
