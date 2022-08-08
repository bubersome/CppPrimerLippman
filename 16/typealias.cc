

#include "Blob.h"

#include <utility>
using std::pair;

#include <string>
using std::string;

typedef Blob<string> StrBlob; 


template<typename T> using twin = pair<T, T>;

template <typename T> using partNo = pair<T, unsigned>;

int main()
{
	// authors is a pair<string, string>
	twin<string> author("Mark", "Twain");
	
	twin<int> win_loss(2, 45);  // win_loss is a pair<int, int>
	
	typedef string Vehicle;
	partNo<Vehicle> car("volvo", 242);  // car is a pair<Vehicle, unsigned>

	return 0;
}
