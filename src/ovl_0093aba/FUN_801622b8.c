/* FUN_801622b8
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x801622b8  body 0x801622b8..0x801626f3  size 1084 B
 * body sha256 071dc805c801e3f98695e568f7ecb686699d0beca6d6fec8c4ff68f05e1226e4
 * provider record sha256 f97826b343fb4b2b2af9a4e09f126da062e4b71ca44564ba9e4f2ea21ff77f5d
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801622b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  short sVar2;
  char cVar5;
  short sVar3;
  ushort uVar4;
  int iVar6;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  short local_40 [2];
  short local_3c;
  undefined1 auStack_38 [32];
  
  if ((*(uint *)(param_1 + 0x28c) < 400) && ((_DAT_800e112a & 6) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x3010100;
    *(undefined1 *)(param_1 + 0x26e) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    uVar1 = func_0x80033604();
    iVar6 = param_1 + 0x14;
    func_0x80037780(0x81fa0,(uVar1 & 0xff) << 4,iVar6,0);
    uVar1 = func_0x80033604();
    func_0x80037780(0x817d0,(uVar1 & 0xff) << 4,iVar6,0);
    uVar1 = func_0x80033604();
    func_0x80037780(0x817d0,(uVar1 & 0xff) << 4,iVar6,0);
    uVar1 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = (uVar1 & 7) * 0x10000 + 0x9000000;
    *(undefined2 *)(param_1 + 500) = 0;
    func_0x80052bd0(1,0);
    func_0x80052c6c(5,0x50,0);
  }
  else {
    if (*(char *)(param_1 + 6) == '\0') {
      *(undefined4 *)(param_1 + 0x1e8) = 0xf00;
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined2 *)(param_1 + 0x1e2) = 0;
      *(undefined2 *)(param_1 + 0x1e4) = 0;
      *(undefined2 *)(param_1 + 0x1f6) = 0;
      *(undefined1 *)(param_1 + 0x206) = 0;
      uVar4 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar4 & 0x1f) + 0x14;
    }
    else if (*(char *)(param_1 + 6) != '\x01') {
      return;
    }
    sVar2 = *(short *)(param_1 + 0x1e0) + -10;
    *(short *)(param_1 + 0x1e0) = sVar2;
    if (sVar2 < 0x1e) {
      *(undefined2 *)(param_1 + 0x1e0) = 0x1e;
    }
    if (0x78 < *(short *)(param_1 + 0x1e0)) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -0x1e;
    }
    cVar5 = *(char *)(param_1 + 0x206) + -1;
    *(char *)(param_1 + 0x206) = cVar5;
    if (cVar5 == -1) {
      uVar1 = func_0x80033604();
      uVar1 = (uVar1 & 0xf) + 10;
      *(char *)(param_1 + 0x206) = (char)uVar1;
      *(char *)(param_1 + 0x207) = (char)(uVar1 >> 1);
    }
    if (*(char *)(param_1 + 0x207) < *(char *)(param_1 + 0x206)) {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + *(char *)(param_1 + 0x206) * 3;
    }
    else {
      *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) + -0x14;
    }
    iVar6 = func_0x80032e74(param_1,(int)*(short *)(param_1 + 0x260),
                            (int)*(short *)(param_1 + 0x262),0x10);
    uVar1 = func_0x80033604();
    if ((uVar1 & 3) == 0) {
      uVar1 = func_0x80033604();
      func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,(int)((uVar1 & 1) * -0x200000) >> 0x10);
    }
    if (0 < iVar6 << 0x10) {
      sVar2 = *(short *)(param_1 + 0x1f6);
      sVar3 = sVar2 + 4;
      *(short *)(param_1 + 0x1f6) = sVar3;
      if (sVar3 < -0x40) {
        *(short *)(param_1 + 0x1f6) = sVar2 + 0xc;
      }
      if (*(short *)(param_1 + 0x1f6) < -0x80) {
        *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 0x10;
      }
      if (*(short *)(param_1 + 0x1f6) < -0x100) {
        *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 0x10;
      }
    }
    if (iVar6 << 0x10 < 0) {
      sVar2 = *(short *)(param_1 + 0x1f6);
      sVar3 = sVar2 + -4;
      *(short *)(param_1 + 0x1f6) = sVar3;
      if (-0x40 < sVar3) {
        *(short *)(param_1 + 0x1f6) = sVar2 + -0xc;
      }
      if (0x80 < *(short *)(param_1 + 0x1f6)) {
        *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -0x10;
      }
      if (0x100 < *(short *)(param_1 + 0x1f6)) {
        *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + -0x10;
      }
    }
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x1f6);
    local_48 = 0;
    local_46 = *(undefined2 *)(param_1 + 0x2b4);
    local_44 = 0;
    func_0x80040e58(&local_48,auStack_38);
    local_48 = *(undefined2 *)(param_1 + 0x1e0);
    local_46 = 0;
    local_44 = 0;
    func_0x8004276c(auStack_38,&local_48,local_40);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (int)local_40[0];
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + (int)local_3c;
    sVar2 = *(short *)(param_1 + 500);
    if ((*(short *)(param_1 + 500) == 0) || (*(short *)(param_1 + 500) = sVar2 + -1, sVar2 == 1)) {
      uVar1 = func_0x80033604();
      if ((uVar1 & 1) != 0) {
        *(undefined4 *)(param_1 + 4) = 0x1050000;
        uVar1 = func_0x80033604();
        if ((uVar1 & 1) != 0) {
          *(undefined4 *)(param_1 + 4) = 0x1070000;
        }
      }
      uVar4 = func_0x80033604();
      *(ushort *)(param_1 + 500) = (uVar4 & 0x1f) + 0x14;
    }
  }
  return;
}
