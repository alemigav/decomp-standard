/* FUN_80006b20
 * image   boot (boot), base 0x80000480
 * address 0x80006b20  body 0x80006b20..0x80006bdb  size 188 B
 * body sha256 299a22264fdb4e2b8ab0f296f34962fa84c30c103d10a052049abbf638ecd78e
 * provider record sha256 54043715d856f3e75d30c18b6efa5cc4281c5ebb7d6ea8455916c1ebc55b11d0
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80006b20(undefined1 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_10;
  
  iVar2 = 0xe;
  puVar1 = (undefined4 *)&DAT_80014fd8;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar2);
  puVar1 = (undefined4 *)&DAT_80014fa0;
  iVar2 = 0;
  _DAT_80014fdc = 1;
  local_10 = CONCAT31(0xff0103,param_1);
  if (DAT_80014f9c != 0) {
    do {
      *puVar1 = local_10;
      puVar1[1] = 0xffffffff;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 2;
    } while (iVar2 < (int)(uint)DAT_80014f9c);
  }
  *(undefined1 *)puVar1 = 0xfe;
  return;
}
