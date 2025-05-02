#include "muzyka.hpp"

Muzyka::Muzyka(const char* sciezkaDoPliku) {
    InitAudioDevice();
    muzyka = LoadMusicStream(sciezkaDoPliku);
    PlayMusicStream(muzyka);
}

void Muzyka::Aktualizuj() {
    UpdateMusicStream(muzyka);
}

void Muzyka::Zakonczenie() {
    StopMusicStream(muzyka);
    UnloadMusicStream(muzyka);
    CloseAudioDevice();
}
