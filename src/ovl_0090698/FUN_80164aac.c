/* FUN_80164aac
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80164aac  body 0x80164aac..0x80164b57  size 172 B
 * body sha256 03e1bf6c190cf7aa7b9e86c6921934ebdba17ee3f257488cedbbcc9290ed12f5
 * provider record sha256 7f1ec6da74eec564081e30ee234f8ab59e46d8527cb3136a97c78d3035b6b19c
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164aac(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined4 *)(param_1 + 4) = 0x1090000;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000300;
    FUN_8016753c(param_1);
  }
  cVar2 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  return;
}
