/* FUN_8017dc48
 * image   ovl_007af7a (ovl), base 0x8017b410
 * address 0x8017dc48  body 0x8017dc48..0x8017ddd7  size 400 B
 * body sha256 ea97c11e440a0da4ca559624d56133fceb1115b12c2064dc3f6ea6ee52fc3ad4
 * provider record sha256 cfd02fd743d705aee0db5f3d08c9e770280a64e85c21c9138efe5993e4b40266
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8017dc48(int param_1,uint param_2,int param_3)

{
  int iVar1;
  char cVar2;
  
  if (param_2 == 0) {
    (&DAT_8017e5dc)[param_1] = 0xff;
    (&DAT_8017e5dd)[param_1] = 0xff;
    (&DAT_8017e5de)[param_1] = 0xff;
    if (param_1 == 0) {
      iVar1 = (byte)(&DAT_8017de20)[param_3 * 2] + 5;
    }
    else {
      iVar1 = (byte)(&DAT_8017de20)[param_3 * 2] + 6;
    }
    (&DAT_8017df58)[iVar1 * 8] = 1;
    return;
  }
  if (param_2 < 100) {
    if (param_2 / 10 == 0) {
      cVar2 = '7';
    }
    else {
      cVar2 = (char)(param_2 / 10) + '\x17';
    }
    (&DAT_8017e5dd)[param_1] = cVar2;
    (&DAT_8017e5dc)[param_1] = (char)param_2 + (char)(param_2 / 10) * -10 + '\x17';
    (&DAT_8017e5de)[param_1] = 0x37;
  }
  else {
    (&DAT_8017e5dc)[param_1] = 0x17;
    (&DAT_8017e5dd)[param_1] = 0x17;
    (&DAT_8017e5de)[param_1] = 0x18;
  }
  if (param_1 == 0) {
    iVar1 = (byte)(&DAT_8017de20)[param_3 * 2] + 5;
  }
  else {
    iVar1 = (byte)(&DAT_8017de20)[param_3 * 2] + 6;
  }
  (&DAT_8017df58)[iVar1 * 8] = 0;
  return;
}
