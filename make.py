import subprocess

def make(command):
    print command
    try:
        print subprocess.check_output(command,shell=True)
    except:
        pass

make("g++ echo-client-simple.cc -o echo-client-simple")
make("g++ echo-server-simple.cc -o echo-client-simple")
make("g++ echo-client.cc inet-client.cc client.cc -o echo-client")
make("g++ echo-server.cc inet-server.cc server.cc -o echo-server")
make("g++ unix-echo-server.cc unix-server.cc server.cc -o unix-echo-server")
make("g++ unix-echo-client.cc unix-client.cc client.cc -o unix-echo-client")
