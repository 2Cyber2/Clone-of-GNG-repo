#include "Framework.h"
#include "Game.h"
//#include "A2-TicTacToe.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    {
        fw::FWWindows framework( 1280, 720 );
        
        Game gameInstance(framework);
        //TicTacToe gameInstance (framework);

        framework.run(gameInstance);
    }
}
