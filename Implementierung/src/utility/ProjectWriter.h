
#include <exception>
using namespace std;

#ifndef __ProjectWriter_h__
#define __ProjectWriter_h__

#include "Project.h"

namespace Model
{
	class Project;
}
namespace Utility
{
	class ProjectWriter;
}

namespace Utility
{
	/**
	 * This class can write the project files and the results.
	 */
	class ProjectWriter
	{

		/// <summary>
		/// Constructor.
		/// </summary>
		/// <param name="p">The project to save.</param>
		public: ProjectWriter(Model::Project p);

		/// <summary>
		/// Saves the whole project.
		/// </summary>
		public: void saveProject();

		/// <summary>
		/// Saves on the analysis results.
		/// </summary>
		public: void saveResults();
	};
}

#endif
