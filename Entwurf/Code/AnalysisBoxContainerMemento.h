
#include <exception>
#include <vector>
using namespace std;

#ifndef __AnalysisBoxContainerMemento_h__
#define __AnalysisBoxContainerMemento_h__

#include "AnalysisBoxMemento.h"

namespace Memento
{
	class AnalysisBoxMemento;
	class AnalysisBoxContainerMemento;
}

namespace Memento
{
	/**
	 * This class is the memento for the AnalysisBoxContainer.
	 */
	class AnalysisBoxContainerMemento
	{
		private: std::vector<Memento::AnalysisBoxMemento*> mementoList;

		/// <summary>
		/// Constructor.
		/// </summary>
		public: void analyseBoxMemento();

		/// <summary>
		/// Returns a list of AnalysisBox mementos.
		/// </summary>
		/// <returns>The list of AnalysisBoxMemento.</returns>
		public: vector<Memento::AnalysisBoxMemento> getAnalysisBoxList();

		/// <summary>
		/// Sets the list of AnalysisBoxMemento
		/// </summary>
		/// <param name="analyseBoxList">The list of the mementos.</param>
		public: void setAnalysisBoxList(vector<Memento::AnalysisBoxMemento> analyseBoxList);
	};
}

#endif
