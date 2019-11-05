#pragma once

#include <memory>
#include <stack>

#include "States.h"

namespace stobon
{
	typedef std::unique_ptr<State> StateReference;

	class StateMachine
	{
	public:
		//Constructor and Destructor
		StateMachine() {}
		~StateMachine() {}

		//Manipulate States
		void AddStates(StateReference newState, bool isReplacing = true);
		void RemoveStates();
		void UpdateChanges();

		StateReference& GetCurrentState();
	private:
		std::stack<StateReference> numStates;
		StateReference newState;
		
		bool isRemoving;
		bool isAdding;
		bool isReplacing;
	};
}