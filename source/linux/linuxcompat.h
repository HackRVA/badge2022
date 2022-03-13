#ifndef LINUXCOMPAT_H
#define LINUXCOMPAT_H

/* username is a global externally visible */
#define NAMESIZE 10

/* for linux we can define here, otherwise it's in username.c */
#ifdef __linux__
char username[NAMESIZE] = { 0 };
#endif

#endif  // LINUXCOMPAT_H
