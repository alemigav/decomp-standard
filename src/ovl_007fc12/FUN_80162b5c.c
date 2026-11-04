/* FUN_80162b5c
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80162b5c  body 0x80162b5c..0x80162cbf  size 356 B
 * body sha256 cf038955e89310f44830d8549c2a081a5b8971024713f245ff8ccfccb9909a0f
 * provider record sha256 58ed11d5fdbeaa4df33e1aa6dbf90478876f4d9b714ed1c42698f78b8178b5b4
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162b5c(int param_1)

{
  short sVar2;
  short sVar3;
  uint uVar1;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x28c);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x400);
  sVar3 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,800);
  if (((uVar4 < 5000) && (sVar2 == 0)) && ((*(ushort *)(param_1 + 0x1f0) & 0x800) != 0)) {
    *(undefined4 *)(param_1 + 4) = 0x1010000;
  }
  if (((uVar4 < 3000) && (sVar3 != 0)) &&
     (((_DAT_800e112a & 0x15) != 0 &&
      (((*(ushort *)(param_1 + 0x1f0) & 0x800) != 0 && (uVar1 = func_0x80033604(), (uVar1 & 1) == 0)
       ))))) {
    *(undefined4 *)(param_1 + 4) = 0x10c0000;
  }
  if ((((uVar4 < 2000) && (sVar2 != 0)) && ((*(ushort *)(param_1 + 0x1f0) & 0x800) != 0)) &&
     (((_DAT_800e112a & 0x17) != 0 && (uVar4 = func_0x80033604(), (uVar4 & 1) != 0)))) {
    *(undefined4 *)(param_1 + 4) = 0x10c0000;
  }
  return;
}
