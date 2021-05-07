#include "stdafx.h"

#include "SFTPclient.h"
#include "SFTPconnection.h"

int main()
{
	const std::string& ip = "127.0.0.1";
	unsigned int port = 22;
	const std::string& username = "testSFTP";

	const std::string& pubKeyFile = "C:\\testSFTP\\public.ppk"; // IMPORTANT only base64 format public key are accepted as file content
	const std::string& privKeyFile = "C:\\testSFTP\\private.ppk";  // IMPORTANT only openSSH format private key file are accepted
	const std::string& privKeyPassPhrase = "privatekeypassword";

	std::vector<std::string> validservers;
	validservers.push_back("11:22:33:44:55:66:77:88:99:00:aa:bb:cc:dd:ee:ff:8c:c7:4a:f5:42:a6:4b:64:07:6b:03:ec:c8:0a:ab:9e");

	systelab::sftp::SFTPClient sftp;
	auto conn = sftp.Connect(ip, port, username, pubKeyFile, privKeyFile, privKeyPassPhrase, validservers);

	if (conn->isConnected())
	{
		conn->upload("c:\\testSFTP\\test1.txt", "uploaded1.txt");
		conn->upload("c:\\testSFTP\\test2.txt", "uploaded2");
		conn->rename("uploaded2", "uploaded2.zip");

		conn->close();
	}

	return 0;
}

