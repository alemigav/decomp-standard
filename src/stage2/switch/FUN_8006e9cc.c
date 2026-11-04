/* FUN_8006e9cc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006e9cc  body 0x8006e9cc..0x8006e9d3  size 8 B
 * body sha256 99f6f163620aa2aa0aa6d12483a282bfa1d42ea24ad75af97e2feb56ffa42019
 * provider record sha256 6582a3c0a9f23eaad5a533d35b089d38c2875bf3b348c2a825bfb5279d50b431
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void switchD_8006e9c4::caseD_0(int param_1)

{
  undefined2 uVar1;
  int unaff_s0;
  undefined2 *unaff_s1;
  
  uVar1 = FUN_800844cc((param_1 + unaff_s0) * 0x10000 >> 0x10);
  *unaff_s1 = uVar1;
  DAT_80115120 = 0;
  return;
}
