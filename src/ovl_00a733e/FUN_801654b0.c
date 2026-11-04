/* FUN_801654b0
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x801654b0  body 0x801654b0..0x80165597  size 232 B
 * body sha256 522a343863aa8640aa01190ead94763125b10f45fe5e6fa2075f93bfaeec6c6e
 * provider record sha256 b9f41b3c7d242ac5ec1d645bc90b390a4b6dcbbfbc9cdc818a9c102740bb5c03
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801654b0(int param_1)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  cVar1 = *(char *)(param_1 + 5);
  if (cVar1 == '\x10') {
    if (*(char *)(param_1 + 0x2bf) != '\0') {
      return;
    }
    *(undefined1 *)(param_1 + 0x2bf) = 0x1e;
  }
  bVar2 = *(byte *)(param_1 + 0x26e);
  if ((cVar1 == '\n') || (uVar5 = 3, cVar1 == '\x10')) {
    uVar5 = 6;
  }
  uVar4 = 0;
  if (uVar5 != 0) {
    do {
      uVar4 = uVar4 + 1;
      uVar3 = func_0x80033604();
      FUN_80167374(param_1,(&DAT_80167db0)[(uint)((uint)bVar2 % 3 != 0) * 4 + (uVar3 & 0xff) & 7],2)
      ;
    } while (uVar4 < uVar5);
  }
  return;
}
