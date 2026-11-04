/* FUN_8000b65c
 * image   boot (boot), base 0x80000480
 * address 0x8000b65c  body 0x8000b65c..0x8000b6ff  size 164 B
 * body sha256 dbd21ff6cc1394705ae7c48d0c20c33dda48afe2000d1432ce34f1b2bdf771f6
 * provider record sha256 bfd8f01fb0eefb83f88b9d01c23e7fff6c176c41e0de414417d3d74f587e200a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000b65c(undefined1 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_10;
  
  puVar2 = (undefined4 *)&DAT_80016470;
  iVar1 = 0;
  _DAT_800164ac = 1;
  local_10 = CONCAT31(0xff0103,param_1);
  DAT_80014fe0 = param_1;
  if (DAT_80014f9c != 0) {
    do {
      *puVar2 = local_10;
      puVar2[1] = 0xffffffff;
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 2;
    } while (iVar1 < (int)(uint)DAT_80014f9c);
  }
  *(undefined1 *)puVar2 = 0xfe;
  return;
}
