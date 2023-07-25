#pragma once

using namespace System;

public ref class Movie
{
public:
    int Id;
    String^ Title;
    String^ Genre;
    String^ ImageUrl;

    Movie();
};
