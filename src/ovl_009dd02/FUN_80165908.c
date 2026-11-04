/* FUN_80165908
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165908  body 0x80165908..0x8016597f  size 120 B
 * body sha256 2626052f6c35b5f08f032764c894c27dbbde4395660ff0249994ed84274d3891
 * provider record sha256 ebec618fe56d93513021d593c4ee57fbbef24e506fc445551d528ab0796d526f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165908(int param_1)

{
  byte bVar1;
  
  if (*(char *)(param_1 + 6) == '\0') {
    FUN_80165980();
    *(undefined1 *)(param_1 + 0x2c1) = 0x46;
    bVar1 = func_0x80033604();
    *(byte *)(param_1 + 0x2c3) = bVar1 % 3 | 0x80;
  }
  else {
    FUN_801656c0(param_1);
  }
  return;
}
