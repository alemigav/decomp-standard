/* FUN_8007e92c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007e92c  body 0x8007e92c..0x8007e967  size 60 B
 * body sha256 69bbcda8f872f3bd5a13b584ef52d9d4700c49deca75a887711fc8a9ac8cf19d
 * provider record sha256 2d109616ad591c4de664800ccb7873c8415c450be866a04b1932de7ba1c80598
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007e92c(uint *param_1)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x7a) = 7;
    *(undefined1 *)((int)param_1 + 0x1ea) = 7;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    *param_1 = *param_1 | 4;
  case 1:
    FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if ((*(char *)(param_1 + 2) == 'E') || (cVar4 = '\x0e', *(char *)(param_1 + 2) == 'O')) {
      cVar1 = *(char *)((int)param_1 + 0x1e9);
      cVar4 = '\x1d';
    }
    else {
      cVar1 = *(char *)((int)param_1 + 0x1e9);
    }
    if (cVar1 == cVar4) {
      *(undefined1 *)((int)param_1 + 7) = 2;
    }
    break;
  case 2:
    *(undefined1 *)((int)param_1 + 7) = 3;
    *(undefined1 *)(param_1 + 0x7a) = 8;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    *(undefined1 *)((int)param_1 + 0x1ea) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    if (*(byte *)(param_1 + 2) < 0x10) {
      iVar6 = *(byte *)(param_1 + 2) + 0x10;
    }
    else {
      iVar6 = *(byte *)(param_1 + 2) - 0x40;
    }
    *(undefined2 *)(param_1 + 0x78) = *(undefined2 *)(&DAT_8010bab8 + iVar6 * 2);
    *(undefined2 *)(param_1 + 0x79) = 0;
    FUN_80032b5c(param_1,0);
    *(undefined2 *)(param_1 + 0x7d) = 5;
    param_1[0xb] = param_1[0xb] + 0x226;
    *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x2a);
    *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)((int)param_1 + 0x2a);
    *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x32);
    *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)((int)param_1 + 0x32);
    *(char *)((int)param_1 + 0x1a2) = *(char *)((int)param_1 + 0x1a2) + -1;
    *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)((int)param_1 + 0x2e);
  case 3:
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + 1;
    param_1[0xb] = param_1[0xb] + sVar2 * 0x1e;
    uVar3 = FUN_80069f1c(param_1 + 10,400,0x8000);
    *(undefined2 *)((int)param_1 + 0x25e) = uVar3;
    *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x32);
    *(undefined2 *)(param_1 + 0xe) = *(undefined2 *)((int)param_1 + 0x32);
    *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x2a);
    *(undefined2 *)(param_1 + 0xd) = *(undefined2 *)((int)param_1 + 0x2a);
    *(undefined2 *)((int)param_1 + 0x36) = *(undefined2 *)((int)param_1 + 0x2e);
    *(char *)((int)param_1 + 0x1a2) = -(char)((int)param_1[0xb] / 0x708);
    FUN_800667d4(param_1 + 10,400,1 << (-((int)param_1[0xb] / 0x708) & 0x1fU),0x8000);
    FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if (*(short *)((int)param_1 + 0x25e) + -300 < (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 7) = 4;
    }
    break;
  case 4:
    *(undefined1 *)((int)param_1 + 7) = 5;
    *(undefined1 *)(param_1 + 0x7a) = 9;
    if (4 < (*(byte *)((int)param_1 + 6) & 0xc)) {
      *(undefined1 *)(param_1 + 0x7a) = 7;
    }
    *(undefined1 *)((int)param_1 + 0x1e9) = 4;
    *(undefined1 *)((int)param_1 + 0x1ea) = 7;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *param_1 = *param_1 & 0xfffffffb;
    FUN_80077f30(1,4,param_1);
    DAT_800e112a = DAT_800e112a | 4;
  case 5:
    *(char *)((int)param_1 + 0x1a2) = -(char)((int)param_1[0xb] / 0x708);
    cVar4 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar4;
    break;
  case 6:
    if (((DAT_800e110c & 0x10000000) == 0) || (param_1 != DAT_800e13ec)) {
      uVar5 = 5;
      if (*(char *)((int)param_1 + 5) == '\x17') {
        uVar5 = 4;
      }
      *(undefined1 *)((int)param_1 + 5) = uVar5;
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 0;
    }
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 7) = 0;
  }
  return;
}
