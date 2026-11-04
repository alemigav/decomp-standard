/* FUN_800022bc
 * image   boot (boot), base 0x80000480
 * address 0x800022bc  body 0x800022bc..0x80002313  size 88 B
 * body sha256 56621a7f03d6d239be9c3b5d31077d5c7d65386c1da2a25c924d86713fccdf08
 * provider record sha256 0a8685b4c6e2bc44bbcdfc4ad47c493876021287cc5307d44b38c92b89ae849e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800022bc(int param_1,int param_2)

{
  FUN_80001510();
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),*(undefined4 *)(param_1 + 0x24));
  (**(code **)(param_2 + 0x24))(*(undefined4 *)(param_2 + 0x28),param_1);
  return 0;
}
