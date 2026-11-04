/* FUN_801650e0
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801650e0  body 0x801650e0..0x80165373  size 660 B
 * body sha256 65bbdc82b3bc36ae6d49dbbfc90af7895291f23a4eb9000fc92fe2f2d30792c5
 * provider record sha256 d7ad55ab95da4a4490980405ca167ef14304d1efdec43c95ffc9ade151649a07
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801650e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  
  (*(code *)(&PTR_LAB_80167f4c)[*(byte *)(param_1 + 5) - 1])();
  *(undefined1 *)(param_1 + 0x2c4) = 2;
  *(undefined1 *)(param_1 + 0x2c5) = 0;
  if (*(char *)(param_1 + 5) != '\x10') {
    func_0x80077d18(2,param_1);
  }
  if (*(char *)(param_1 + 5) != '\x01') {
    uVar1 = (&DAT_80167d97)[*(byte *)(param_1 + 5)];
    uVar2 = (&DAT_80167dac)[(uint)*(byte *)(param_1 + 0x26e) % 3];
    local_28 = 300;
    local_26 = 0;
    local_24 = 0;
    FUN_8016747c(param_1,uVar2,uVar1,&local_28);
    local_28 = 0xff9c;
    FUN_8016747c(param_1,uVar2,uVar1,&local_28);
  }
  if (((0x13 < _DAT_800e1322) && (*(char *)(param_1 + 0x2bd) == '\0')) &&
     (*(char *)(param_1 + 0x2d0) == '\0')) {
    sVar5 = 600;
    if ((_DAT_800e10ec & 0x20) != 0) {
      sVar5 = 500;
    }
    if (*(short *)(param_1 + 0x1f2) < sVar5) {
      iVar3 = (uint)*(ushort *)(param_1 + 0x2c2) -
              (uint)(byte)(&DAT_80167fab)[*(byte *)(param_1 + 5)];
      *(short *)(param_1 + 0x2c2) = (short)iVar3;
      if (iVar3 * 0x10000 < 1) {
        *(undefined1 *)(param_1 + 0x2c0) = 0;
        *(undefined2 *)(param_1 + 0x2c2) = 0x28;
        if (*(char *)(param_1 + 0x2b4) == '\0') {
          uVar4 = 0x1090000;
          goto LAB_801652dc;
        }
      }
    }
    else {
      iVar3 = (uint)*(ushort *)(param_1 + 0x2c2) -
              (uint)(byte)(&DAT_80167f97)[*(byte *)(param_1 + 5)];
      *(short *)(param_1 + 0x2c2) = (short)iVar3;
      if (iVar3 * 0x10000 < 1) {
        *(undefined1 *)(param_1 + 0x2c0) = 0;
        *(undefined2 *)(param_1 + 0x2c2) = 0x28;
        uVar4 = 0x1080000;
LAB_801652dc:
        *(undefined1 *)(param_1 + 0x2d0) = 1;
        *(undefined4 *)(param_1 + 4) = uVar4;
        *(undefined2 *)(param_1 + 0x1e0) = *(undefined2 *)(param_1 + 0x2d2);
        *(undefined2 *)(param_1 + 0x1e2) = *(undefined2 *)(param_1 + 0x2d4);
        *(undefined2 *)(param_1 + 0x1e4) = *(undefined2 *)(param_1 + 0x2d6);
        *(undefined1 *)(param_1 + 0x2ba) = *(undefined1 *)(param_1 + 5);
        *(undefined1 *)(param_1 + 699) = *(undefined1 *)(param_1 + 6);
        *(undefined1 *)(param_1 + 700) = *(undefined1 *)(param_1 + 7);
        return;
      }
    }
  }
  *(uint *)(param_1 + 4) =
       (uint)*(byte *)(param_1 + 0x2ba) * 0x10000 + (uint)*(byte *)(param_1 + 699) * 0x100 +
       (uint)*(byte *)(param_1 + 700) + 0x1000000;
  FUN_80162114(param_1,param_2,param_3);
  return;
}
