use Device::SerialPort;
use Control::CLI;

$port = "/dev/ttyACM1";
$speed = 9600;
$cli = new Control::CLI($port);
$cli->connect(BaudRate=>$speed,
           Parity          => 'none',
           DataBits        => 8,
          StopBits        => 1,
        Handshake       => 'none',
);

open(TTY, "+</dev/tty") or die "no tty: $!";


system "stty  cbreak </dev/tty >/dev/tty 2>&1";
while(1){
$_ = getc(TTY);
($o= "255#255\n");
($o = "000#510\n")if(/a/);
($o = "000#000\n") if(/s/);
($o ="510#510\n")if(/w/);
($o= "510#000\n")if(/d/);
(last) if(/\+/);
print $o, $/;
$cli->print($o);
}
$cli->disconect;
undef $serial
