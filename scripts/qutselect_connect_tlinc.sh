#!/bin/sh
#
# This is a startup script for qutselect which initates a
# ThinLinc session to a thinlinc server
#
# It receives the following inputs:
#
# $1 = PID of qutselect
# $2 = serverType (SRSS, RDP, VNC)
# $3 = 'true' if dtlogin mode was on while qutselect was running
# $4 = the resolution (either 'fullscreen' or 'WxH')
# $5 = the selected color depth (8, 16, 24)
# $6 = the current max. color depth (8, 16, 24)
# $7 = the selected keylayout (e.g. 'de' or 'en')
# $8 = the domain (e.g. 'FZR', used for RDP)
# $9 = the username
# $10 = the password if requested from the user
# $11 = the servername (hostname) to connect to

TLCLIENT=/opt/thinlinc/bin/tlclient

#####################################################
# check that we have 8 command-line options at hand
if [ $# -lt 11 ]; then
   printf "ERROR: missing arguments!"
   exit 2
fi

# catch all arguments is some local variables
parentPID="${1}"
serverType="${2}"
dtlogin="${3}"
resolution="${4}"
colorDepth="${5}"
curDepth="${6}"
keyLayout="${7}"
domain="${8}"
username="${9}"
password="${10}"
serverName="${11}"

# check if the hostname is the same like the 
# server we should connect to and if yes we go and exit immediately
if [ `hostname` != "${serverName}" ]; then

  # variable to prepare the command arguments
  cmdArgs=""

  # show the options tab when the gui pops up
  cmdArgs="$cmdArgs -h options"

  # username
  cmdArgs="$cmdArgs -u $username"

  # password
  cmdArgs="$cmdArgs -p $password"

  # execute tlclient
  ${TLCLIENT} ${cmdArgs} ${serverName}
  if [ $? != 0 ]; then
    printf "ERROR: ${TLCLIENT} returned invalid return code"
    exit 2
  fi
fi

return 0