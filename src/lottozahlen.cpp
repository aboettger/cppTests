/*
 * lottozahlen.cpp
 *
 *  Created on: 03.03.2015
 *      Author: aboettger
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

const int MAX_LOTTOZAHLEN = 6;

int
main (int argc, char **argv)
{
  std::random_device rd;
  std::mt19937 engine (rd ());
  std::uniform_int_distribution<int> dist1to49 (1, 49);
  std::uniform_int_distribution<int> dist0to9 (0, 9);
  std::vector<int> lottozahlen;

  for (int i = 0; i < MAX_LOTTOZAHLEN; ++i)
    {
      bool flag = false;
      int lottozahl = 0;
      do
	{
	  flag = false;
	  lottozahl = dist1to49 (engine);
	  for (std::vector<int>::size_type j = 0; j < lottozahlen.size (); ++j)
	    {
	      if (lottozahlen[j] == lottozahl)
		{
		  flag = true;
		  break;
		}
	    }
	}
      while (flag);
      lottozahlen.push_back (lottozahl);
    }

  std::sort (lottozahlen.begin (), lottozahlen.end ());

  std::cout << "Lottozahlen: ";
  for (std::vector<int>::size_type i = 0; i < lottozahlen.size (); ++i)
    {
      std::cout << lottozahlen[i] << " ";
    }

  std::cout << std::endl;

  std::cout << "Zusatzzahl: " << dist0to9 (engine);

  return (0);
}
