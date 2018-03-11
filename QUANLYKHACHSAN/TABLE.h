#pragma once
#include <iostream>
#include <map>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
class TABLE
{
public:
	typedef vector< string > Row;
	enum class Alignment { LEFT, RIGHT };

	Alignment alignment(unsigned i) const
	{
		return _alignment[i];
	}

private:
	char _horizontal;
	char _vertical;
	char _corner;
	Row _current;
	vector< Row > _rows;
	vector< unsigned > mutable _width;
	map< unsigned, Alignment > mutable _alignment;

	static string repeat(unsigned times, char c);
	unsigned columns() const;
	void determineWidths() const;
	void setupAlignment() const;

public:
	TABLE();
	~TABLE();

	TABLE(char horizontal = '-', char vertical = '|', char corner = '+') : _horizontal(horizontal), _vertical(vertical), _corner(corner)
	{}

	void setAlignment(unsigned i, Alignment alignment);
	//Alignment alignment(unsigned i) const;
	char vertical() const;
	char horizontal() const;
	void add(string const & content);
	void endOfRow();
	template <typename Iterator>

	void addRow(Iterator begin, Iterator end);
	template <typename Container>
	void addRow(Container const & container);
	vector< Row > const & rows() const;
	void setup() const;
	string ruler() const;
	int width(unsigned i) const;

	friend ostream & operator<<(ostream & stream, TABLE const & table);
};

