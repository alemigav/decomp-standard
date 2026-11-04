/* FUN_80163038
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163038  body 0x80163038..0x801631d3  size 412 B
 * body sha256 e4db417d463275c111f40f5f62515099c397196c0780deee7ca2b34afb31c640
 * provider record sha256 ac20afc4e7d5c9811c50022cbcca96bd5581fce7bf5733d8e9b939fe39005333
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80163038(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  byte bVar3;
  short sVar2;
  short sVar4;
  
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(uint *)(param_1 + 0x1e8) = (*(byte *)(param_1 + 0x2b4) + 1) * 0x1000000 + 0xf00;
    uVar1 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
    *(ushort *)(param_1 + 0x2b6) = uVar1;
    sVar4 = -1;
    if (0 < (int)((uint)uVar1 << 0x10)) {
      sVar4 = 1;
    }
    if (((int)*(char *)(param_1 + 0x2cc) == (int)sVar4) &&
       (bVar3 = *(char *)(param_1 + 0x2cd) + 1, *(byte *)(param_1 + 0x2cd) = bVar3, 2 < bVar3)) {
      *(undefined1 *)(param_1 + 0x2cd) = 0;
      *(short *)(param_1 + 0x2b6) = -*(short *)(param_1 + 0x2b6);
    }
    *(char *)(param_1 + 0x2cc) = (char)sVar4;
    *(undefined2 *)(param_1 + 500) = 0x20;
    *(undefined1 *)(param_1 + 0x2c0) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfe;
  }
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x2b6);
  sVar2 = func_0x80032e74(param_1,_DAT_800e1158,_DAT_800e1160,0x40);
  sVar4 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar4 + -1;
  if (((sVar4 == 1) || (sVar2 == 0)) || (*(short *)(param_1 + 0x2b6) == 0)) {
    *(undefined1 *)(param_1 + 5) = 2;
    *(undefined2 *)(param_1 + 6) = 0;
    FUN_80162ea8(param_1);
    FUN_80164d9c(param_1);
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80033648(param_1);
  func_0x80089d54(param_1,param_2,param_3,0x100);
  func_0x80033648(param_1);
  return;
}
