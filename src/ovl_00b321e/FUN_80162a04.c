/* FUN_80162a04
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162a04  body 0x80162a04..0x80162bff  size 508 B
 * body sha256 c31547292564b3a523df684f71f96dd35fc2cc20f02840ba0e7b258c28eb3537
 * provider record sha256 d407ae2aca13975c22d0fb35cabc41b355470b197805af518c41e8f7f4e91b93
 * callees 9 direct (9 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162a04(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    iVar2 = func_0x80089d54();
    if (iVar2 != 0) {
      *(undefined2 *)(param_1 + 500) = 0x14;
      *(undefined1 *)(param_1 + 0x207) = 0x14;
      *(undefined1 *)(param_1 + 7) = 1;
      *(undefined1 *)(param_1 + 0x206) = 0;
      *(undefined4 *)(param_1 + 0x1e8) = 0xa000000;
      func_0x80089d54(param_1,param_2,param_3,0x100);
      DAT_800e1136 = 1;
    }
    func_0x80032b5c(param_1,0);
    func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x18);
    if ((*(byte *)(param_1 + 0x2bd) & 1) == 0) {
      *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + -0x37;
    }
  }
  else {
    iVar2 = func_0x800331b8();
    iVar2 = (uint)*(ushort *)(param_1 + 500) - iVar2;
    *(short *)(param_1 + 500) = (short)iVar2;
    if ((iVar2 * 0x10000 < 1) || (*(char *)(param_1 + 0x207) < '\x01')) {
      *(undefined2 *)(param_1 + 6) = 0x200;
      DAT_800e1135 = 3;
    }
    else {
      uVar3 = func_0x80033604();
      if ((uVar3 & 7) == 0) {
        uVar3 = func_0x80033604();
        FUN_80166270(param_1,(&DAT_80166700)[uVar3 & 3],2);
      }
      func_0x80089d54(param_1,param_2,param_3,0x100);
      func_0x80033648(param_1);
      bVar1 = *(byte *)(param_1 + 0x206);
      *(byte *)(param_1 + 0x206) = bVar1 + 1;
      if ((bVar1 & 2) == 0) {
        iVar2 = *(int *)(param_1 + 0x2c) + -0x20;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x2c) + 0x20;
      }
      *(int *)(param_1 + 0x2c) = iVar2;
      if ((*(byte *)(param_1 + 0x206) & 3) == 0) {
        *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -3;
        iVar2 = func_0x80059e00(3,0);
        if (iVar2 == 2) {
          FUN_8016622c(0);
          *(undefined2 *)(param_1 + 6) = 0x200;
        }
      }
    }
  }
  return;
}
