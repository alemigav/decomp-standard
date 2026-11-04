/* FUN_8016285c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016285c  body 0x8016285c..0x80162b2b  size 720 B
 * body sha256 649802e9a76206d0e4a9d2456c0c9f096688df114bb3c6781c9953198e0dec96
 * provider record sha256 7c0c3e46284a82096bc8e4b711f48778fd6e248686f70d46dbe66fbe1dcb0573
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016285c(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  short sVar2;
  ushort uVar3;
  char cVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 0x2d3) == '\0') {
    iVar5 = -0x7ff1eed0;
  }
  else {
    iVar5 = _DAT_800e13ec;
  }
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
  case 1:
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    func_0x80032b5c(param_1,0);
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000300;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0x1f) + 0x14;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    sVar2 = func_0x80032e74(param_1,*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x30),0x40
                           );
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + sVar2;
    func_0x80089d54(param_1,param_2,param_3,0x400);
    if (sVar2 == 0) {
      *(undefined1 *)(param_1 + 6) = 4;
    }
    sVar2 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar2;
    if (sVar2 == -1) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x5000300;
    *(undefined1 *)(param_1 + 6) = 5;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0x1f) + 10;
    *(undefined2 *)(param_1 + 0x1e0) = 300;
  case 5:
    func_0x80032dbc(param_1,*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x30),0x10);
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
    func_0x80089d54(param_1,param_2,param_3,0x400);
    sVar2 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar2;
    bVar1 = false;
    if (sVar2 == -1) {
LAB_80162a7c:
      bVar1 = true;
    }
    else if (*(char *)(param_1 + 0xd) == -1) {
      if ((*(uint *)(param_1 + 0x1ac) & 1) == 0) {
        iVar5 = func_0x80032e74(param_1,*(undefined4 *)(iVar5 + 0x28),*(undefined4 *)(iVar5 + 0x30),
                                0x200);
        if (iVar5 != 0) goto LAB_80162a7c;
      }
      else {
        bVar1 = true;
      }
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    iVar5 = FUN_8016741c(param_1,0x5dc,0x10cc);
    if (iVar5 != 0) {
      *(undefined1 *)(param_1 + 6) = 6;
    }
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x1e8) = 0x7000300;
    *(undefined2 *)(param_1 + 0x1e0) = 100;
    *(undefined1 *)(param_1 + 6) = 7;
  case 7:
    func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x2b6));
    cVar4 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar4;
    break;
  case 8:
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(undefined2 *)(param_1 + 0x2b4) = 0xf;
  default:
    break;
  }
  FUN_80167938(param_1);
  return;
}
