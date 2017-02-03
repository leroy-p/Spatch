# Spatch

The project's goal is to generate an environment with servers accessible via Spatch.

n Servers are gonna be created with different permission for different users
through Spatch the users are able to connect to them or not depending on their permissions

Each server will be created with a conf.xml telling its name, the rigths etc... 

IPtable : 

	ipUser1|IPserverallowed1/IPserverallowed2/IPserverallowedn/...
    ipUser2|IPserverallowed1/IPserverallowed2/IPserverallowedn/...
    ipUser3|BAN

# Schema

User:
	
    1) On connection either create a new line in the IPtable or read corresponding one
    2) Try to connect to a server success/fail according to its rights

Server:

	1) Runnable creating n servers.
    2) Create confs file
    3) Delete everything on closing
	
 Spatch:
 	
    1) on Launch display IP and port
    2) proxy between client and server
    3) command line gestion
    4) admin actions
  

<h2>Etienne</h2>
User management

<h2>Fabricio</h2>
Server Creation

<h2>Fawzi</h2>
Proxy

 
 # command

	connect [ipServer] : Connection to server
	show servers : display list of server accessible
    show users : display list of all users
    
   Admin command :
   
   	kick [user]
    allow -u [user] -s [server]
    ban [user]
    forbid [user]
   
   