/* FUN_8002ddb4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002ddb4  body 0x8002ddb4..0x8002de0b  size 88 B
 * body sha256 02facf7013467772c17ee3452d4cdac054a37a9c5c605119c531c2fb98f2f56c
 * provider record sha256 3e8ffcf961b6356e03272f32242d1996a547de55d0bbc902dd76321fd871c011
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002ddb4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*(code *)**(undefined4 **)(param_1 + 4))(param_1,1,0x24);
  *(undefined4 **)(param_1 + 0x164) = puVar1;
  *puVar1 = FUN_8002dbdc;
  puVar1[1] = FUN_8002dd34;
  FUN_8002da50();
  return;
}
