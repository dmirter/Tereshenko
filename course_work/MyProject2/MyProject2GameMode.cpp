#include "MyProject2GameMode.h"
#include "MyProject2Character.h"

AMyProject2GameMode::AMyProject2GameMode()
{
	DefaultPawnClass = AMyProject2Character::StaticClass();	
}
