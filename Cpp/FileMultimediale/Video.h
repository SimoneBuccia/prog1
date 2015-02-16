#ifndef _VIDEO_H_
#define _VIDEO_H_

#include "FileMultimediale.h"

class Video : public File {
	friend ostream & operator<<(ostream &, const Video &);
	friend istream & operator>>(istream &, Video &);
	
	private:
		char * Au;
		char * So;
		char * Da;
	public:
		Video(const char * = "", int = 0, const char * = "",const char * = "",const char * = "",const char * = "");
		Video(const Video &);
		virtual ~Video();
		const Video & operator=(const Video &);
		
		const char * getAu() const;
		void setAu(const char *);
		const char * getSo() const;
		void setSo(const char *);
		const char * getDa() const;
		void setDa(const char *);
		
		virtual void stampa() const;
		virtual void memorizza(ostream &) const;
};

#endif
