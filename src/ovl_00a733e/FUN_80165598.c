/* FUN_80165598
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80165598  body 0x80165598..0x80165687  size 240 B
 * body sha256 ebbacb9fe42915b8c235af5aa90dca3618203b269e5727330f006c10302525a3
 * provider record sha256 c798508c0b5a6c5a28180b13cb2073877de2f09f05c30798341aa8d9087721a1
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165598(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (uint)((uint)*(byte *)(param_1 + 0x26e) % 3 != 0) * 4;
  uVar2 = 0;
  if (*(char *)(param_1 + 4) == '\x02') {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = func_0x80033604();
      FUN_80167374(param_1,(&DAT_80167db0)[iVar3 + (uVar1 & 7)],4);
    } while (uVar2 < 3);
  }
  else {
    do {
      uVar2 = uVar2 + 1;
      uVar1 = func_0x80033604();
      FUN_80167374(param_1,(&DAT_80167db0)[iVar3 + (uVar1 & 7)],5);
    } while (uVar2 < 4);
  }
  return;
}
