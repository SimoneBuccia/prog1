#ifndef _LETTERA_H_
#define _LETTERA_H_

#include "Manoscritto.h"

class Lettera : public Manoscritto {
	friend ostream & operator<<(ostream &, const Lettera &);
	friend istream & operator>>(istream &, Lettera &);
	
	private:
		char * Mit;
		char * Des;
	public:
		Lettera(const int = 0, const char * = "",const char * = "",const int = 0,const char * = "",const char * = "");
		Lettera(const Lettera &);
		const Lettera & operator=(const Lettera &);
		virtual ~Lettera();
		
		const char * getMit() const;
		const char * getDes() const;
		
		void setMit(const char *);
		void setDes(const char *);
		
		virtual void memorizzaDati(ostream &) const;
		virtual ostream & visualizzaDati(ostream &) const;
 };

#endif
