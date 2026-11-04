/* FUN_801653fc
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x801653fc  body 0x801653fc..0x80165443  size 72 B
 * body sha256 096bdb68f0f714bce0802953c501f5b4d8fbdaead825490587478718944518f6
 * provider record sha256 82ac25a7687844be0637fd2eb5fc4a9e04900964aa43edcb01ec689c43632cb5
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801653fc(int param_1)

{
  byte bVar1;
  
  FUN_80164e88();
  *(undefined1 *)(param_1 + 0x2c1) = 0xc5;
  bVar1 = func_0x80033604();
  *(byte *)(param_1 + 0x2c3) = bVar1 & 3;
  FUN_80165310(param_1,7,2);
  return;
}
