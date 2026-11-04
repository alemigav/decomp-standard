/* FUN_80166370
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80166370  body 0x80166370..0x80166413  size 164 B
 * body sha256 369fd972a7ff7801a33e3be97eeb544d0b8b18e4136cb2bed111ddf9e1c784e0
 * provider record sha256 42e21dae6d7affe3321d894a6c6ff143f36ad67fd138bd01985ad427e40ef196
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80166370(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  bVar1 = *(byte *)(param_1 + 0x2bd);
  iVar3 = *(int *)(param_1 + 0x208);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x2bd) = 1;
    func_0x800341dc(iVar3,_DAT_800c76b0);
    *(undefined1 *)(param_1 + 0x207) = 0x5a;
  }
  *(short *)(iVar3 + 4) = *(short *)(iVar3 + 4) + 8;
  *(short *)(iVar3 + 6) = *(short *)(iVar3 + 6) + 8;
  cVar2 = *(char *)(param_1 + 0x207);
  *(char *)(param_1 + 0x207) = cVar2 + -1;
  if (cVar2 == '\x01') {
    *(undefined1 *)(param_1 + 0x2bd) = 2;
  }
  return;
}
