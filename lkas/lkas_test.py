import socket
import struct
from piracer.vehicles import PiRacerStandard

def main():
    host = '192.168.1.155'
    port = 3333

    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((host, port))

    server_socket.listen()

    piracer = PiRacerStandard()

    print('echo server start')

    client_soc = None

    try:
        client_soc, addr = server_socket.accept()

        print('connected client addr:', addr)

        while True:
            data = client_soc.recv(8)
            if not data:
                break
            double_data = struct.unpack('>d', data)[0]
            #print('recv msg:', double_data)

            steering = double_data * 0.008

            print('steering: ', steering)

            piracer.set_throttle_percent(0.45)
            piracer.set_steering_percent(steering)

    except KeyboardInterrupt:
        print('KeyboardInterrupt received. Server closing...')

    finally:
        if client_soc:
            client_soc.close()
        server_socket.close()
        piracer.set_throttle_percent(0.0)
        piracer.set_steering_percent(0.0)

    print('server is terminated')

if __name__ == '__main__':
    main()
