/* This file has been generated by the Hex-Rays decompiler.
   Copyright (c) 2007-2014 Hex-Rays <info@hex-rays.com>

   Detected compiler: GNU C++
*/

#include <defs.h>


//-------------------------------------------------------------------------
// Function declarations

void (*init_proc())(void);
// int printf(const char *format, ...);
// char *fgets(char *s, int n, FILE *stream);
// int puts(const char *s);
// int __gmon_start__(void); weak
// FILE *fopen(const char *filename, const char *modes);
// __int32 strtol(const char *nptr, char **endptr, int base);
void _do_global_dtors_aux();
int frame_dummy();
signed int validate();
int give_flag();
int __cdecl main(int argc, const char **argv, const char **envp);
int *_libc_csu_init();
void _i686_get_pc_thunk_bx();
void (*_do_global_ctors_aux())(void);
void term_proc();

//-------------------------------------------------------------------------
// Data declarations

int _CTOR_LIST__ = 4294967295; // weak
int _DTOR_LIST__[] = { 4294967295 }; // weak
_UNKNOWN _DTOR_END__; // weak
int _JCR_LIST__ = 0; // weak
char completed_6159; // weak
int dtor_idx_6161; // weak
int square[]; // weak
// extern _UNKNOWN _gmon_start__; weak


//----- (08048394) --------------------------------------------------------
void (*init_proc())(void)
{
  if ( &_gmon_start__ )
    __gmon_start__();
  frame_dummy();
  return _do_global_ctors_aux();
}
// 8048420: using guessed type int __gmon_start__(void);

//----- (08048460) --------------------------------------------------------
#error "8048463: positive sp value has been found (funcsize=2)"

//----- (08048490) --------------------------------------------------------
void _do_global_dtors_aux()
{
  int v0; // eax@2
  int i; // ebx@2

  if ( !completed_6159 )
  {
    v0 = dtor_idx_6161;
    for ( i = ((&_DTOR_END__ - (_UNKNOWN *)_DTOR_LIST__) >> 2) - 1; dtor_idx_6161 < (unsigned int)i; v0 = dtor_idx_6161 )
    {
      dtor_idx_6161 = v0 + 1;
      ((void (*)(void))_DTOR_LIST__[v0 + 1])();
    }
    completed_6159 = 1;
  }
}
// 8049F1C: using guessed type int _DTOR_LIST__[];
// 804A040: using guessed type char completed_6159;
// 804A044: using guessed type int dtor_idx_6161;

//----- (080484F0) --------------------------------------------------------
int frame_dummy()
{
  int result; // eax@1

  result = _JCR_LIST__;
  if ( _JCR_LIST__ )
    result = 0;
  return result;
}
// 8049F24: using guessed type int _JCR_LIST__;

//----- (08048514) --------------------------------------------------------
signed int validate()
{
  int v0; // eax@8
  signed int result; // eax@9
  int v2[30]; // [sp+0h] [bp-90h]@2
  int v3; // [sp+78h] [bp-18h]@1
  int v4; // [sp+7Ch] [bp-14h]@1
  int i; // [sp+80h] [bp-10h]@1
  int j; // [sp+84h] [bp-Ch]@5
  int v7; // [sp+88h] [bp-8h]@48
  int v8; // [sp+8Ch] [bp-4h]@58

  v3 = 0;
  v4 = 0;
  for ( i = 0; i <= 29; ++i )
    v2[i] = 0;
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; j <= 3; ++j )
    {
      if ( square[j + 4 * i] <= 0 || square[j + 4 * i] > 30 )
        return 0;
      v0 = square[j + 4 * i] - 1;
      ++v2[v0];
    }
  }
  for ( i = 0; i <= 29; ++i )
  {
    if ( v2[i] > 1 )
      return 0;
  }
  for ( i = 0; i <= 3; ++i )
    v3 += square[i];
  for ( i = 0; i <= 3; ++i )
  {
    v4 = 0;
    for ( j = 0; j <= 3; ++j )
      v4 += square[j + 4 * i];
    if ( v4 != v3 )
      return 0;
  }
  for ( i = 0; i <= 3; ++i )
  {
    v4 = 0;
    for ( j = 0; j <= 3; ++j )
      v4 += square[i + 4 * j];
    if ( v4 != v3 )
      return 0;
  }
  v4 = 0;
  for ( i = 0; i <= 3; ++i )
    v4 += square[5 * i];
  if ( v4 == v3 )
  {
    v4 = 0;
    for ( i = 0; i <= 3; ++i )
      v4 += square[4 * i + 3 - i];
    if ( v4 == v3 )
    {
      for ( i = 0; i <= 3; ++i )
      {
        v7 = i;
        v4 = 0;
        for ( j = 0; j <= 3; ++j )
        {
          v4 += square[v7-- + 4 * j];
          if ( v7 < 0 )
            v7 = 3;
        }
        if ( v4 != v3 )
          return 0;
      }
      for ( i = 0; i <= 3; ++i )
      {
        v8 = i;
        v4 = 0;
        for ( j = 0; j <= 3; ++j )
        {
          v4 += square[v8++ + 4 * j];
          if ( v8 > 3 )
            v8 = 0;
        }
        if ( v4 != v3 )
          return 0;
      }
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
// 804A060: using guessed type int square[];
// 8048514: using guessed type int var_90[30];

//----- (08048817) --------------------------------------------------------
int give_flag()
{
  FILE *stream; // ST18_4@1
  char s; // [sp+1Eh] [bp-2Ah]@1
  int v3; // [sp+3Ch] [bp-Ch]@1

  v3 = *MK_FP(__GS__, 20);
  stream = fopen("/home/tripathy/Documents/CTF_Problems/Reversing/Franklin/flag.txt", "r");
  fgets(&s, 30, stream);
  puts("Yay flag!");
  printf("%s", &s);
  return *MK_FP(__GS__, 20) ^ v3;
}

//----- (0804888E) --------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int result; // eax@2
  signed int i; // [sp+18h] [bp-8h]@3
  signed int j; // [sp+1Ch] [bp-4h]@4

  if ( argc == 17 )
  {
    for ( i = 0; i <= 3; ++i )
    {
      for ( j = 0; j <= 3; ++j )
        square[j + 4 * i] = strtol(argv[j + 4 * i + 1], 0, 10);
    }
    if ( validate() )
      give_flag();
    else
      puts("No flag :(.");
    result = 0;
  }
  else
  {
    puts("You need to input 16 numbers.");
    result = 1;
  }
  return result;
}
// 804A060: using guessed type int square[];

//----- (08048950) --------------------------------------------------------
int *_libc_csu_init()
{
  init_proc();
  return &_CTOR_LIST__;
}
// 8049F14: using guessed type int _CTOR_LIST__;

//----- (080489C2) --------------------------------------------------------
void _i686_get_pc_thunk_bx()
{
  ;
}

//----- (080489D0) --------------------------------------------------------
void (*_do_global_ctors_aux())(void)
{
  void (*result)(void); // eax@1
  int *v1; // ebx@2

  result = (void (*)(void))_CTOR_LIST__;
  if ( _CTOR_LIST__ != -1 )
  {
    v1 = &_CTOR_LIST__;
    do
    {
      --v1;
      result();
      result = (void (*)(void))*v1;
    }
    while ( *v1 != -1 );
  }
  return result;
}
// 8049F14: using guessed type int _CTOR_LIST__;

//----- (080489FC) --------------------------------------------------------
void term_proc()
{
  _do_global_dtors_aux();
}

#error "There were 1 decompilation failure(s) on 11 function(s)"