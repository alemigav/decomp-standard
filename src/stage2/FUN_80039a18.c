/* FUN_80039a18
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80039a18  body 0x80039a18..0x80039a97  size 128 B
 * body sha256 a6b4c84d697b6ecae7e21ea054af38cdbffb5611ca98eabbff65671163010644
 * provider record sha256 1c355154726f8442e6d27ad4fd0c4fd1132b6cc6917bf452c6d0415b6ee553d9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80039a18(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  param_3 = param_3 >> 1;
  puVar1 = (undefined2 *)(param_1 + param_3 * 2);
  puVar2 = (undefined2 *)(param_2 + param_3 * 2);
  if ((((param_5 == 0) || (param_5 == 8)) || (param_5 == 9)) ||
     ((param_5 == 0x1f || (param_5 == 0x26)))) {
    FUN_8003994c();
  }
  else {
    for (; param_3 != 0; param_3 = param_3 - 1) {
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
      *puVar1 = *puVar2;
    }
  }
  return;
}
