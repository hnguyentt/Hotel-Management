#include "TABLE.h"



TABLE::TABLE()
{
}


TABLE::~TABLE()
{
}
void TABLE::setAlignment(unsigned i, Alignment alignment)
{
	_alignment[i] = alignment;
}

enum class Alignment { LEFT, RIGHT };

char TABLE::vertical() const
{
	return _vertical;
}
char TABLE::horizontal() const
{
	return _horizontal;
}

void TABLE::add(string const & content)
{
	_current.push_back(content);
}

void TABLE::endOfRow()
{
	_rows.push_back(_current);
	_current.assign(0, "");
}

template <typename Iterator>
void TABLE::addRow(Iterator begin, Iterator end)
{
	for (auto i = begin; i != end; ++i) {
		add(*i);
	}
	endOfRow();
}

template <typename Container>
void TABLE::addRow(Container const & container)
{
	addRow(container.begin(), container.end());
}

vector< TABLE::Row > const & TABLE::rows() const
{
	return _rows;
}

void TABLE::setup() const
{
	determineWidths();
	setupAlignment();
}

string TABLE::ruler() const
{
	string result;
	result += _corner;
	for (auto width = _width.begin(); width != _width.end(); ++width) {
		result += repeat(*width, _horizontal);
		result += _corner;
	}

	return result;
}

int TABLE::width(unsigned i) const
{
	return _width[i];
}

string TABLE::repeat(unsigned times, char c)
{
	string result;
	for (; times > 0; --times)
		result += c;

	return result;
}

unsigned TABLE::columns() const
{
	return _rows[0].size();
}

void TABLE::determineWidths() const
{
	_width.assign(columns(), 0);
	for (auto rowIterator = _rows.begin(); rowIterator != _rows.end(); ++rowIterator) {
		Row const & row = *rowIterator;
		for (unsigned i = 0; i < row.size(); ++i) {
			_width[i] = _width[i] > row[i].size() ? _width[i] : row[i].size();
		}
	}
}

void TABLE::setupAlignment() const
{
	for (unsigned i = 0; i < columns(); ++i) {
		if (_alignment.find(i) == _alignment.end()) {
			_alignment[i] = Alignment::LEFT;
		}
	}
}

ostream & operator<<(ostream & stream, TABLE const & table)
{
	table.setup();
	stream << table.ruler() << "\n";
	for (auto rowIterator = table.rows().begin(); rowIterator != table.rows().end(); ++rowIterator) {
		TABLE::Row const & row = *rowIterator;
		stream << table.vertical();
		for (unsigned i = 0; i < row.size(); ++i) {
			auto alignment = table.alignment(i) == TABLE::Alignment::LEFT ? left : right;
			stream << setw(table.width(i)) << alignment << row[i];
			stream << table.vertical();
		}
		stream << "\n";
		stream << table.ruler() << "\n";
	}

	return stream;
}