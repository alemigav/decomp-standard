/* FUN_801643f4
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801643f4  body 0x801643f4..0x8016454b  size 344 B
 * body sha256 30f4f25d8a742a5d9b97a4c937dc956e1bcb4054c3377614dd0c036b61052e7c
 * provider record sha256 cd6c41e6d886ffb9b6f7235ca7bcac393247d8de10294e8ff273d67cb94b4c54
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801643f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x10040);
      func_0x80089d54(param_1,param_2,param_3,0x10040);
      if ((**(uint **)(param_1 + 0x214) & 0x20000) == 0) {
        return;
      }
      *(undefined1 *)(param_1 + 5) = 1;
      *(undefined2 *)(param_1 + 6) = 0;
      *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 500) = 0xf;
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x25d) = 9;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfe;
  }
  iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
  if ((iVar2 != 0) || (iVar2 = func_0x80089d54(param_1,param_2,param_3,0x40), iVar2 != 0)) {
    *(undefined1 *)(param_1 + 7) = 2;
    *(undefined4 *)(param_1 + 0x1e8) = 0xc000000;
    func_0x80089d54(param_1,param_2,param_3,0x10040);
    *(undefined1 *)(param_1 + 0x2c1) = 0x44;
    *(undefined1 *)(param_1 + 0x2c3) = 3;
  }
  return;
}
