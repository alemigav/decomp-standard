/* FUN_80091a38
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091a38  body 0x80091a38..0x80091a6f  size 52 B
 * body sha256 fb35f9c77c01fb15f671c58b151ddb8f7cf82cd748878915dceb9e174c63c425
 * provider record sha256 e6663dfcad2e21509f3b8574f832e1416edd54dec445c48435c2e2452a01fea4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 switchD_8009177c::caseD_6(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_800837ac(&DAT_800e8ce0,0x89);
  uVar2 = 0x13;
  if (iVar1 == 0) {
    uVar2 = 0x12;
  }
  return uVar2;
}
