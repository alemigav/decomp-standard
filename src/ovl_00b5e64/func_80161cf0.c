/* func_80161cf0
 * image   ovl_00b5e64 (ovl), base 0x80161cf0
 * address 0x80161cf0  body 0x80161cf0..0x80161d4f  size 96 B
 * body sha256 58ad0d7e64dfaf3c1cc521d53789a4bf569cbe88dec9c6c204d994721f1cf656
 * provider record sha256 08e64ee0288aa25404ff0cecba55b50432186f90e5f214eb6bc8fec1fab0bdcf
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void processEntry entry(void)

{
  int in_a0;
  
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    (*(code *)(&PTR_FUN_80161f80)[*(byte *)(in_a0 + 4)])
              (in_a0,*(undefined4 *)(in_a0 + 0x1a4),*(undefined4 *)(in_a0 + 0x218));
  }
  return;
}
