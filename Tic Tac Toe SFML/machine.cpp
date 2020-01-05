#include "machine.h"

namespace stobon
{
	void StateMachine::AddStates(StateReference newState, bool isReplacing)
	{
		this->isAdding = true;
		this->isReplacing = isReplacing;
		this->newState = std::move(newState);
	}

	void StateMachine::RemoveStates()
	{
		this->isRemoving = true;
	}

	void StateMachine::UpdateChanges()
	{
		if (this->isRemoving && !this->numStates.empty())
		{
			this->numStates.pop();
			if (!this->numStates.empty())
			{
				this->numStates.top()->Resume();
			}
			this->isRemoving = false;
		}

		if (this->isAdding)
		{
			if (!this->numStates.empty())
			{
				if (this->isReplacing)
				{
					this->numStates.pop();
				}
				else
				{
					this->numStates.top()->Pause();
				}
			}
			this->numStates.push(std::move(this->newState));
			this->numStates.top()->Initialize();
			this->isAdding = false;
		}

	}
	StateReference& StateMachine::GetCurrentState() 
	{
		return this->numStates.top();
	}

}